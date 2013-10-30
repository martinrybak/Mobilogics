//
//  ReceiveCommand.h
//  Barcode
//
//  Created by Mikimoto on 13/1/24.
//
//

#import "Command.h"

@protocol ReceiveCommandProtocol

- (BOOL)isHandle:(NSData *)data;
- (void)handle:(NSData *)data;

/**
 * Got receive barcode string.
 *
 * @retval NSString*
 */
- (NSString *)receiveString;

/**
 * Got receive barcode binary data.
 *
 * @retval NSData*
 */
- (NSData *)receiveData;

/**
 * Got receive binary data as unsign integer.
 *
 * @retval NSUInteger*
 */
- (NSNumber *)receiveNumber;

@end

@interface ReceiveCommand : Command <ReceiveCommandProtocol>{
  @protected
  NSData *body;
}

- (void)handle:(unsigned char *)hex length:(NSUInteger)i;

@end
