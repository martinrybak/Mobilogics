  //
  //  MLScanner.h
  //  BarcodeFramework
  //
  //  Created by mikimoto on 2010/7/9.
  //  Copyright 2010 MobiLogics. All rights reserved.
  //

#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>
#import "MLEABase.h"

@class ExecuteCommand;

/**
 * @brief Create and maintain accessory connection. After you had connection, you can scan barcode through iPDT380, iScan or AScan.
 *
 * Connection is an Translate Layer, it can used to create, maintain connection and execute commands which is define in Command Layer.
 */
@interface MLScanner : MLEABase

/**
 * Set the framework initalize and setup. Before you start using other function, you must call this method once.
 * \par Compatable Models:
 * - All Models
 */
- (void)setup;

  // - (NSArray *)connectedAccessory __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA,__MAC_NA,__IPHONE_NA,__IPHONE_NA);

/**
 * Detect scanner accessory is connected or not.
 *
 * @retval  TRUE If one of iPDT380, iScan or aScan is connected and work fine.
 * @retval FALSE If nor iPDT380, iScan or aScan is not connected, or device error. In this status, execute command will be ignore.
 *
 * \par Compatable Models:
 * - All Models
 */
- (BOOL)isConnected;

/**
 * Add handler to handle iPDT380, iScan or aScan connected event.
 * Handler must implement NotificationHandler protocol<br>
 * If you use UIView, you can add handler in viewDidLoad.
 * Please remove handler in viewDidUnload.
 * @see removeAccessoryDidConnectNotification:(NSObject<NotificationHandler> *)
 * @see addAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *)
 * @see removeAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *)
 * @see NotificationHandler::connectNotify
 *
 * @param handler The object implement NotificationHandler protocol which can handle accessory connected notification.
 *
 * \par Compatable Models:
 * - All Models
 */
- (void)addAccessoryDidConnectNotification:(NSObject <NotificationHandler> *)handler;

/**
 * Remove handler not to handle iPDT380, iScan or aScan connected event
 * After you remove handler, you will not trigger with iPDT380, iScan or aScan connected event.
 * @see addAccessoryDidConnectNotification:(NSObject<NotificationHandler> *)
 * @see addAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *)
 * @see removeAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *)
 * @see NotificationHandler::connectNotify
 *
 * @param handler The object implement NotificationHandler protocol.
 *
 * \par Compatable Models:
 * - All Models
 */
- (void)removeAccessoryDidConnectNotification:(NSObject <NotificationHandler> *)handler;

/**
 * Add handler to handle iPDT380, iScan or aScan disconnected event.
 * Handler must implement NotificationHandler protocol<br>
 * If you use UIView, you can add handler in viewDidLoad.
 * Please remove handler in viewDidUnload.
 * @see addAccessoryDidConnectNotification:(NSObject<NotificationHandler> *)
 * @see removeAccessoryDidConnectNotification:(NSObject<NotificationHandler> *)
 * @see removeAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *)
 * @see NotificationHandler::disconnectNotify
 *
 * @param handler The object implement NotificationHandler protocol which can handle accessory disconnected notification.
 *
 * \par Compatable Models:
 * - All Models
 */
- (void)addAccessoryDidDisconnectNotification:(NSObject <NotificationHandler> *)handler;

/**
 * Remove handler not to handle iPDT380, iScan or aScan disconnected event.
 * After you remove handler, you will not trigger with iPDT380 or iScan disconnected event.
 * @see addAccessoryDidConnectNotification:(NSObject<NotificationHandler> *)
 * @see removeAccessoryDidConnectNotification:(NSObject<NotificationHandler> *)
 * @see addAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *)
 * @see NotificationHandler::disconnectNotify
 *
 * @param handler The object implement NotificationHandler protocol.
 *
 * \par Compatable Models:
 * - All Models
 */
- (void)removeAccessoryDidDisconnectNotification:(NSObject <NotificationHandler> *)handler;

/**
 * Add handler to handle receive command layer object which receive from iPDT380, iScan or aScan.
 * Send Command and Receive Command is Asynchronous, so after you send command, you can fire and forget.<br>
 * Handler must implement ReceiveCommandHandler protocol<br>
 * If you use UIView, you can add handler in viewDidLoad.
 * Please remove handler in viewDidUnload.
 * @see removeReceiveCommandHandler:(NSObject<ReceiveCommandHandler> *)
 * @see ReceiveCommandHandler
 *
 * @param handler The object implement ReceiveCommandHandler protocol which can handle receive command.
 *
 * \par Compatable Models:
 * - All Models
 */
- (void)addReceiveCommandHandler:(NSObject <ReceiveCommandHandler> *)handler;

/**
 * Remove handler which handle receive command layer object event
 * After you remove handler, you will not trigger with iPDT380, iScan or aScan receive command event.
 * @see addReceiveCommandHandler:(NSObject<ReceiveCommandHandler> *)
 * @see ReceiveCommandHandler
 *
 * @param handler The object implement ReceiveCommandHandler protocol.
 *
 * \par Compatable Models:
 * - All Models
 */
- (void)removeReceiveCommandHandler:(NSObject <ReceiveCommandHandler> *)handler;

/**
 * Get MLConnection instance.
 * You can't alloc or new MLConnection instance. You can used this method to get a MLConnection instance.
 *
 * @retval MLConnection* MLConnection instance.
 */
+ (id)sharedInstance;

/**
 * Tigger scanner accessory to scan barcode
 *
 * \par Compatable Models:
 * - All Models
 */
- (void)scan;

/**
 * Get scanner accessory battery info
 *
 * @see batteryOnCharge
 * @see batteryCapacity
 *
 * \par Compatable Models:
 * - iPDT5
 * - aScan
 * - new iPDT380 ( the old version iPDT380 before 2013/05 will not support ).
 */
- (void)batteryRemain;

/**
 * set scanner accessory battery charge
 *
 * \par Compatable Models:
 * - iPDT5
 * - new iPDT380 ( the old version iPDT380 before 2013/05 will not support ).
 */
- (void)chargeBattery;

/**
 * set scanner accessory vibra motor strength
 *
 * @param i=0 turn vibra motor off
 * @param i=1 turn vibra motor strength small
 * @param i=2 turn vibra motor strength medium
 * @param i=3 turn vibra motor strength big
 *
 * \par Compatable Models:
 * - iPDT5
 * - aScan
 * - new iPDT380 ( the old version iPDT380 before 2013 will not support ).
 */
- (void)vibraMotorStrength:(enum vibraMotorStrengthDef)i;

/**
 * switch scanner accessory beep on or off
 *
 * @param status TRUE turn beep on.
 * @param status FALSE turn beep off.
 *
 * \par Compatable Models:
 * - iPDT5
 * - new iPDT380 ( the old version iPDT380 before 2013 will not support ).
 */
- (void)beepSwitch:(BOOL)status;

/**
 * detect app layout need upside down or not
 *
 * @retval  TRUE if app layout need upsidedown
 * @retval FALSE if app layout do't need upsidedown
 *
 * \par Compatable Models:
 * - All Models
 */
- (BOOL)interfaceOrientationNeedUpsideDown;

/**
 * get battery capacity. before you get this information, you must call batteryRemain function first.
 *
 * @retval NSNumber return battery capacity information with percentage number, over 100% means in charging. For example: 12.5 means 12.5%.
 *
 * @see batteryOnCharge
 *
 * \par Compatable Models:
 * - iPDT5
 * - new iPDT380 ( the old version iPDT380 before 2013 will not support ).
 */
- (NSNumber *)batteryCapacity;

/**
 * get status of battery on charge or not.
 *
 * @retval YES battery on charge.
 * @retval  NO battery not on charge.
 *
 * @see batteryCapacity
 *
 * \par Compatable Models:
 * - iPDT5
 * - new iPDT380 ( the old version iPDT380 before 2013 will not support ).
 */
- (BOOL)batteryOnCharge;

/**
 * get accessory sound is on or off
 *
 * @see vibraMotorStrength
 * @see powerRemainPercent
 * @see powerRemainInmV
 * @see powerRemainInMin
 * @see updateAccessoryInfo
 *
 * @retval YES accessory beep after action
 * @retval  NO accessory mute
 *
 * \par Compatable Models:
 * - iPDT5
 * - new iPDT380 ( the old version iPDT380 before 2013 will not support ).
 */
- (BOOL)isBeepStatusOn;

/**
 * get accessory vibra motor strength
 *
 * @retval    vibraMotorStrengthOff accessory vibra motor is off.
 * @retval  vibraMotorStrengthSmall accessory vibra motor strength is small.
 * @retval vibraMotorStrengthMedium accessory vibra motor strength is medium.
 * @retval    vibraMotorStrengthBig accessory vibra motor strength is big.
 *
 * @see isBeepStatusOn
 * @see powerRemainPercent
 * @see powerRemainInmV
 * @see powerRemainInMin
 * @see updateAccessoryInfo
 *
 * \par Compatable Models:
 * - iPDT5
 * - new iPDT380 ( the old version iPDT380 before 2013 will not support ).
 */
- (enum vibraMotorStrengthDef)vibraMotorStrength;

/**
 * get accessory power remain percentage
 *
 * @retval Integer 0% <= n <= 99%, unit is percentage
 *
 * @see isBeepStatusOn
 * @see vibraMotorStrength
 * @see powerRemainInmV
 * @see powerRemainInMin
 * @see updateAccessoryInfo
 *
 * \par Compatable Models:
 * - iPDT5
 * - new iPDT380 ( the old version iPDT380 before 2013 will not support ).
 */
- (int)powerRemainPercent;

/**
 * get accessory power remain in mV
 *
 * @retval Integer 0mV <= n <= 9999mV, n is between 0V ~ 9.999V
 *
 * @see isBeepStatusOn
 * @see vibraMotorStrength
 * @see powerRemainPercent
 * @see powerRemainInMin
 * @see updateAccessoryInfo
 *
 * \par Compatable Models:
 * - iPDT5
 * - new iPDT380 ( the old version iPDT380 before 2013 will not support ).
 */
- (int)powerRemainInmV;

/**
 * get accessory power remain in minute
 *
 * @retval Integer 0 min <= n <= 9999 min
 *
 * @see isBeepStatusOn
 * @see vibraMotorStrength
 * @see powerRemainPercent
 * @see powerRemainInmV
 * @see updateAccessoryInfo
 *
 * \par Compatable Models:
 * - iPDT5
 * - new iPDT380 ( the old version iPDT380 before 2013 will not support ).
 */
- (int)powerRemainInMin;

/**
 * update accessory information manually
 *
 * @see isBeepStatusOn
 * @see vibraMotorStrength
 * @see powerRemainPercent
 * @see powerRemainInmV
 * @see powerRemainInMin
 *
 * \par Compatable Models:
 * - iPDT5
 * - new iPDT380 ( the old version iPDT380 before 2013 will not support ).
 */
- (void)updateAccessoryInfo;

/**
 * use this method to turn on/off prevent conitune fast scan process. If your barcode contains 'CE', please turn this option to FALSE.
 *
 * @param on  TRUE turn prevent conitune fast scan process on, default is on.
 * @param on FALSE turn prevent conitune fast scan process off.
 *
 * \par Compatable Models:
 * - All Models
 */
- (void)preventFastInputWithinFastContinueInput:(BOOL)on;

/**
 * return prevent contiune fast scan process flag.
 *
 * @retval YES trun on
 * @retval NO turn off
 *
 * \par Compatable Models:
 * - All Models
 */
- (BOOL)isPreventFastInput;

/**
 * Sync Switch for 30 pin connector
 *
 * \par Compatable Models:
 * - new iPDT380 ( the old version iPDT380 before 2013 will not support ).
 */
- (void)configSyncSwitch:(BOOL)on;

- (void)execute:(ExecuteCommand *)command;

/**
 * turn sdk compatable to old iPDT380/iScan mode on. If you use iPDT380/iScan had 'CE' error, you should turn it on.
 *
 * \par Compatable Models:
 * - All Models
 */
- (void)turnCompatableModeOn;

/**
 * turn sdk compatable to old iPDT380/iScan mode off. This is default setting.
 *
 * \par Compatable Models:
 * - All Models
 */
- (void)turnCompatableModeOff;

@end
