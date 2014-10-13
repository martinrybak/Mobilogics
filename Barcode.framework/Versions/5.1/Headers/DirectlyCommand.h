//
//  DirectlyCommand.h
//  Barcode
//
//  Created by Mikimoto on 13/1/25.
//
//

#import "ExecuteCommand.h"

@interface DirectlyCommand : ExecuteCommand {
  @private
  NSData *data;
}

- (void)setCommandString:(NSString *)command;
@end
