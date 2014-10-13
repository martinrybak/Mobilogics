//
//  ReadNSData.h
//  BarcodeCommand
//
//  Created by mikimoto on 2010/3/19.
//  Copyright 2010 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (ISCPDataFormat)

- (unsigned char)readByte:(unsigned int)offset;
- (unsigned short)readShort:(unsigned int)offset;
- (unsigned long)readLong:(unsigned int)offset;
- (NSString *)readString:(NSUInteger)offset;
- (NSString *)readString:(NSUInteger)offset length:(NSUInteger)length;
- (NSString *)readHex:(NSUInteger)length;
- (NSString *)readHex:(NSUInteger)offset length:(NSUInteger)length;

+ (int)countBinary:(unichar)ch index:(int)i;
+ (NSData *)readInputAscii2Bin:(NSString *)str separatedByString:(NSString *)sep;

- (NSData *)toISCPFormat;

+ (NSData *)fromHex:(unsigned char *)hex length:(NSUInteger)i;

@end
