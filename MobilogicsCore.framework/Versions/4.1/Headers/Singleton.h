//
//  Singleton.h
//  MobilogicsCore
//
//  Created by Mikimoto 莊志鴻 on 12/4/27.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MobilogicsCore_Singleton_h
#define MobilogicsCore_Singleton_h

#define DEFINE_SHARED_INSTANCE_USING_BLOCK(block) \
  static dispatch_once_t pred = 0;                \
  __strong static id _sharedObject = nil;         \
  dispatch_once(&pred, ^ {                        \
        _sharedObject = block();                  \
      });                                         \
  return _sharedObject;                           \

#endif
