//
//  ReceiveCommand.h
//  Barcode
//
//  Created by Mikimoto on 13/1/24.
//
//

#import "Command.h"

@class MLAccessory;

/**
 * @brief ReceiveCommand Protocol
 */
@protocol ReceiveCommandProtocol
@required
- (BOOL)canProcess:(NSData *)data;
- (BOOL)canCompatableProcess:(NSData *)data;
- (void)handle:(NSData *)data accessory:(MLAccessory *)mla preventFastInputFilter:(BOOL)on;
- (void)compatableHandle:(NSData *)data accessory:(MLAccessory *)mla preventFastInputFilter:(BOOL)on;
- (NSData *)receiveData;
- (NSNumber *)receiveNumber;

/**
 * Got receive barcode string.
 *
 * @retval NSString* barcode string
 */
- (NSString *)receiveString;

@end

/**
 * @brief After barcode scan, you will receive a ReceiveCommand.
 *
 * You can use [ReceiveCommand receiveString] to get barcode string.
 *
 * @see ReceiveCommandHandler::isHandler:(ReceiveCommand *)
 * @see ReceiveCommandHandler::handleRequest:(ReceiveCommand *)
 */
@interface ReceiveCommand : Command <ReceiveCommandProtocol>{
  @protected
  NSMutableData *body;
  BOOL          preventFastInput;
  MLAccessory   *mlAccessory;
}

- (void)defaultValueInit;

- (id)clone;
- (NSData *)unpackageKey;

@end
