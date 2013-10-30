//
//  ScanShot.h
//  BarcodeCommand
//
//  Created by mikimoto on 2010/4/16.
//  Copyright 2010 Mobilogics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ExecuteCommand.h"

/**
 * @brief A command to trigger iPDT380, iScan or aScan to scan barcode.
 */
@interface ScanShot : ExecuteCommand {}

/**
 * Get ScanShot instance.
 * You can't alloc or new ScanShot instance. You can used this method to get a ScanShot instance.
 *
 * @retval ScanShot* ScanShot instance.
 */
// +(id)sharedInstance;

@end
