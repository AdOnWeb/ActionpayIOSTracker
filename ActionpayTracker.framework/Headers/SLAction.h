//
//  SLAction.h
//  ActionpayTracker
//
//  Created by Dmitry Ponomarev on 8/20/13.
//  Copyright (c) 2013 Actionpay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SLAction : NSObject

/**
 * Action name
 */
@property (nonatomic, copy) NSString *name;

/**
 * Price value. All actions with this param is unicals
 */
@property (nonatomic, copy) NSString *price;

/**
 * Order id for unique
 */
@property (nonatomic, copy) NSString *orderId;

/**
 * Sent flag
 */
@property (nonatomic, assign) BOOL sent;

/**
 * Failed counter
 */
@property (nonatomic, assign) NSInteger failed;

/**
 * Custom apid
 */
@property (nonatomic, copy) NSString *apid;

// Initialization

- (id)init:(NSString *)name
     price:(NSString *)price
   orderId:(NSString *)orderId
      apid:(NSString *)apid;

+ (id)action:(NSString *)name;

+ (id)action:(NSString *)name
       price:(NSString *)price
     orderId:(NSString *)orderId;

+ (id)action:(NSString *)name
       price:(NSString *)price
     orderId:(NSString *)orderId
        apid:(NSString *)apid;

+ (id)actionByDict:(NSDictionary *)info;

// Helpers

- (NSDictionary *)dictionary;
- (NSDictionary *)params;

- (BOOL)isExpired;
- (BOOL)isUnique;

@end
