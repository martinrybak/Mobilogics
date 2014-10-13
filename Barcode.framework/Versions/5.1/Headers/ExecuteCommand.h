//
//  ExecuteCommand.h
//  Barcode
//
//  Created by Mikimoto on 13/1/24.
//
//

#import "Command.h"

@protocol ExecuteCommandProtocol
@required
- (NSData *)iscanPackage;
- (NSData *)ipdt380Package;
- (NSData *)ipdt3801O01Package;
- (NSData *)ipdt3802I15Package;
- (NSData *)ascan1HM3Package;
- (NSData *)ascan2I15Package;
//- (NSData *)ipdt5Package;
- (NSData *)ipdt51O01Package;
- (NSData *)ipdt52I15Package;
@end

@interface ExecuteCommand : Command <ExecuteCommandProtocol>{}

- (NSData *)emptyPackage;

@end
