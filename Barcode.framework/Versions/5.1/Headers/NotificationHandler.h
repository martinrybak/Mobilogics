//
//  NotificationHandler.h
//  BarcodeFramework
//
//  Created by mikimoto on 2010/7/12.
//  Copyright 2010 MobiLogics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ExternalAccessory/ExternalAccessory.h>
#import "ReceiveCommand.h"

/**
 * @brief iPDT380, iScan or aScan connected or disconnected event handler must implement this protocol.
 */
@protocol NotificationHandler

/**
 * When hardware connected, it will callback this method ( if you addAccessoryDidConnectNotification to MLConnection ).
 *
 * @see MLScanner::addAccessoryDidConnectNotification:(NSObject <NotificationHandler> *)
 */
- (void)connectNotify;

/**
 * When hardware disconnected, it will callback this method ( if you addAccessoryDidDisconnectNotification to MLConnection ).
 *
 * @see MLScanner::addAccessoryDidDisconnectNotification:(NSObject <NotificationHandler> *)
 */
- (void)disconnectNotify;

@end

/**
 * @brief Recevie command handler must implement this protocol
 */
@protocol ReceiveCommandHandler

/**
 * After Barcode framework recevie command, it will callback this method to make sure that handler will handle it or not.
 * If return TRUE, framework will call method: handleRequest:.
 *
 * @param command The object implement ReceiveCommandProtocol protocol which can return will handle receive command or not.
 * @retval  TRUE The handler will handle this command.
 * @retval FALSE The handler will not handle this command.
 *
 * @see handleRequest:
 */
- (BOOL)isHandler:(ReceiveCommand *)command;

/**
 * After Barcode framework recevie command and isHandler: returns TRUE, it will call this method and let handler take care this command.
 *
 * @param command The object implement ReceiveCommandProtocol protocol which can handle receive command.
 *
 * @see isHandler:
 */
- (void)handleRequest:(ReceiveCommand *)command;

/**
 * After call MLScanner system trigger command, for example like batteryRemain.
 * You will got Barcode Framework callback notification in this method.
 */
- (void)handleInformationUpdate;

@end
