/*
 *  Command.h
 *  Barcode Command Framework
 *
 *  Created by mikimoto on 2010/3/20.
 *  Copyright 2010 MobiLogics Inc. All rights reserved.
 *
 */

/**
 * @brief Command layer objects must implement this protocol
 */
@protocol CommandProtocol
@required
- (NSData *)iscan;
- (NSData *)ascan;
- (NSData *)ipdt5;
- (NSData *)ascanIntermec;
@end

/**
 * @brief A simple implement of command layer object.
 */
@interface Command : NSObject <CommandProtocol>

@end
