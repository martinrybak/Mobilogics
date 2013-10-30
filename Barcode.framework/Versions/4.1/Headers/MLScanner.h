//
//  TranslateConnection.h
//  BarcodeFramework
//
//  Created by mikimoto on 2010/7/9.
//  Copyright 2010 MobiLogics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>

/**
 * @brief Create and maintain accessory connection. After you had connection, you can scan barcode through iPDT380, iScan or AScan.
 *
 * Connection is an Translate Layer, it can used to create, maintain connection and execute commands which is define in Command Layer.
 */
@interface MLScanner : NSObject <EAAccessoryDelegate>{
  @private
  NSMutableArray      *connectNotificationHandlerArray;
  NSMutableArray      *disconnectNotificationHandlerArray;
  NSMutableArray      *receiveCommandArray;
  NSMutableArray      *receiveCommandHandlerArray;
  NSMutableArray      *accessoryArray;
  NSMutableDictionary *connectNotificationQueue;
  BOOL                connectNotificationQueueIsRunning;
  NSNumber            *batteryCapacity;
}

/**
 * Set the framework initalize and setup. Before you start using other function, you must call this method once.
 */
- (void)setup;

/**
 * Get the connected accessories array.
 *
 * @retval NSArray* The Array include connected accessories which you supported.
 */
- (NSArray *)connectedAccessory;

/**
 * Detect scanner accessory is connected or not.
 *
 * @retval TRUE If one of iPDT380, iScan or aScan is connected and work fine.
 * @retval FALSE If nor iPDT380, iScan or aScan is not connected, or device error. In this status, execute command will be ignore.
 */
- (BOOL)isConnected;

/**
 * Execute command.
 *
 * Send command layer object to iPDT380, iScan and aScan, but when isConnected return FALSE, command will be ignore.
 * @see isConnected
 * @see ScanShot
 *
 * @param command The command implement NSObject<CommandProtocol> in command layer that you want to send to scanner accessory.
 */
- (void)execute:(NSObject <CommandProtocol> *)command;

/**
 * Add handler to handle iPDT380, iScan or aScan connected event.
 * Handler must implement NotificationHandler protocol<br>
 * If you use UIView, you can add handler in viewDidLoad.
 * Please remove handler in viewDidUnload.
 * @see removeAccessoryDidConnectNotification:(NSObject<NotificationHandler> *) handler
 * @see addAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *) handler
 * @see removeAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *) handler
 * @see NotificationHandler
 *
 * @param handler The object implement NotificationHandler protocol which can handle accessory connected notification.
 */
- (void)addAccessoryDidConnectNotification:(NSObject <NotificationHandler> *)handler;

/**
 * Remove handler not to handle iPDT380, iScan or aScan connected event
 * After you remove handler, you will not trigger with iPDT380, iScan or aScan connected event.
 * @see addAccessoryDidConnectNotification:(NSObject<NotificationHandler> *) handler
 * @see addAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *) handler
 * @see removeAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *) handler
 * @see NotificationHandler
 *
 * @param handler The object implement NotificationHandler protocol.
 */
- (void)removeAccessoryDidConnectNotification:(NSObject <NotificationHandler> *)handler;

/**
 * Add handler to handle iPDT380, iScan or aScan disconnected event.
 * Handler must implement NotificationHandler protocol<br>
 * If you use UIView, you can add handler in viewDidLoad.
 * Please remove handler in viewDidUnload.
 * @see addAccessoryDidConnectNotification:(NSObject<NotificationHandler> *) handler
 * @see removeAccessoryDidConnectNotification:(NSObject<NotificationHandler> *) handler
 * @see removeAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *) handler
 * @see NotificationHandler
 *
 * @param handler The object implement NotificationHandler protocol which can handle accessory disconnected notification.
 */
- (void)addAccessoryDidDisconnectNotification:(NSObject <NotificationHandler> *)handler;

/**
 * Remove handler not to handle iPDT380, iScan or aScan disconnected event.
 * After you remove handler, you will not trigger with iPDT380 or iScan disconnected event.
 * @see addAccessoryDidConnectNotification:(NSObject<NotificationHandler> *) handler
 * @see removeAccessoryDidConnectNotification:(NSObject<NotificationHandler> *) handler
 * @see addAccessoryDidDisconnectNotification:(NSObject<NotificationHandler> *) handler
 * @see NotificationHandler
 *
 * @param handler The object implement NotificationHandler protocol.
 */
- (void)removeAccessoryDidDisconnectNotification:(NSObject <NotificationHandler> *)handler;

/**
 * Add handler to handle receive command layer object which receive from iPDT380, iScan or aScan.
 * Send Command and Receive Command is Asynchronous, so after you send command, you can fire and forget.<br>
 * Handler must implement ReceiveCommandHandler protocol<br>
 * If you use UIView, you can add handler in viewDidLoad.
 * Please remove handler in viewDidUnload.
 * @see removeReceiveCommandHandler:(NSObject<ReceiveCommandHandler> *) handler
 * @see ReceiveCommandHandler
 *
 * @param handler The object implement ReceiveCommandHandler protocol which can handle receive command.
 */
- (void)addReceiveCommandHandler:(NSObject <ReceiveCommandHandler> *)handler;

/**
 * Remove handler which handle receive command layer object event
 * After you remove handler, you will not trigger with iPDT380, iScan or aScan receive command event.
 * @see addReceiveCommandHandler:(NSObject<ReceiveCommandHandler> *) handler
 * @see ReceiveCommandHandler
 *
 * @param handler The object implement ReceiveCommandHandler protocol.
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
 */
- (void)scan;

/**
 * Get scanner accessory battery info
 */
- (void)batteryRemain;

/**
 * set scanner accessory battery charge
 */
- (void)chargeBattery;

/**
 * set scanner accessory vibra motor strength
 * @param i 0=off, 1=small, 2=medium, 3=big
 */
- (void)vibraMotorStrength:(NSUInteger)i;

/**
 * switch scanner accessory beep on or off
 * @param status TRUE=on, FALSE=off
 */
- (void)beepSwitch:(BOOL)status;

/**
 * detect app layout need upside down or not
 * @retval BOOL if app layout need upsidedown return TRUE, else return FALSE
 */
- (BOOL)interfaceOrientationNeedUpsideDown;

/**
 * get battery capacity. before you get this information, you must call batteryRemain function first.
 * @retval NSNumber return battery capacity information with percentage number, over 100% means in charging. For example: 12.5 means 12.5%, 110% means in charging.
 */
- (NSNumber *)batteryCapacity;
@end
