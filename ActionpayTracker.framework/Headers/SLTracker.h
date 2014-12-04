//
//  SLTracker.h
//  ActionpayTracker
//
//  Created by Dmitry Ponomarev on 8/20/13.
//  Copyright (c) 2013 Actionpay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SLAction.h"

@protocol SLTrackerDelegate <NSObject>

@optional

- (BOOL)onBeginTrack:(id)sender action:(SLAction *)action;
- (BOOL)onBeginSend:(id)sender action:(SLAction *)action;
- (void)onEndSend:(id)sender action:(SLAction *)action;

@end

@interface SLTracker : NSObject
{
  // Session value
  NSString *_session;
  
  // Wait for next request
  NSTimeInterval    _waitFor;
  
  // Last update time
  NSTimeInterval    _lastUpdateTime;
}

/**
 * Application ID
 */
@property (nonatomic, readonly) NSString *appID;

/**
 * Send statistic every milliseconds
 */
@property (nonatomic, readonly) NSTimeInterval updateInterval;

/**
 * Application URL scheme
 */
@property (nonatomic, retain) NSString *scheme;

/**
 * Callback URL for install event
 */
@property (nonatomic, retain) NSString *installCallbackUrl;

/**
 * Install action code
 */
@property (nonatomic, retain) NSString *installEventCode;

/**
 * Test mode
 */
@property (nonatomic) BOOL test;

/**
 * Tracker Delegate
 */
@property (nonatomic) id<SLTrackerDelegate> delegate;

/**
 * Action queue
 */
@property (nonatomic, readonly) id queue;

/**
 * Client
 */
@property (nonatomic, readonly) id client;

/**
 * Is active
 */
@property (nonatomic, readonly, getter = isActive) BOOL active;

/**
 * Pause work
 */
@property (nonatomic, readwrite, getter = isPause) BOOL pause;

/**
 * Init tracker
 *
 * @param appID application ID
 * @param scheme
 * @param install url default 'return'
 * @return self
 */
+ (id)init:(NSString *)appID
    scheme:(NSString *)scheme
installUrl:(NSString *)installUrl;

/**
 * Init tracker
 *
 * @param appID application ID
 * @param scheme
 * @param install url default 'return'
 * @param installEvent install event code. Default install
 * @return self
 */
+ (id)  init:(NSString *)appID
      scheme:(NSString *)scheme
  installUrl:(NSString *)installUrl
installEvent:(NSString *)installEventCode;

/**
 * Init tracker
 *
 * @param appID application ID
 * @param scheme
 * @param install url default 'return'
 * @param installEvent install event code. Default install
 * @param test test mode
 * @return self
 */
+ (id)  init:(NSString *)appID
      scheme:(NSString *)scheme
  installUrl:(NSString *)installUrl
installEvent:(NSString *)installEventCode
        test:(BOOL)test;

/**
 * Init tracker in test mode
 *
 * @param scheme
 * @param install url default 'return'
 * @return self
 */
+ (id)initTest:(NSString *)scheme
    installUrl:(NSString *)installUrl;

/**
 * Process install url $scheme://$install_url
 *
 * @param application
 * @param url
 * @return success flag
 */
- (BOOL)trackUrl:(UIApplication *)application
             url:(NSURL *)url;

/**
 * Start install tracking
 *
 * @return is Processed
 */
- (BOOL)trackInstall;

/**
 * Tracker shared object
 *
 * @return tracker
 */
+ (SLTracker *)sharedTracker;

////////////////////////////////////////////////////////////////////////////////
#pragma mark – Tracking actions
////////////////////////////////////////////////////////////////////////////////

/**
 * Start internet connection listener
 */
- (void)connectionListenerStart;

/**
 * Stop internet connection listener
 *
 * @param stopReachabilityNotifier
 */
- (void)connectionListenerStop:(BOOL)stopReachabilityNotifier;

/**
 * Set autosend interval
 *
 * @param updateInterval Maximal is 6 Hours
 * @param repeat flag
 */
- (void)setUpdateInterval:(NSTimeInterval)updateInterval
                   repeat:(BOOL)repeat;

/**
 * Send action queue
 *
 * @return success status
 */
- (BOOL)send;

/**
 * Track action
 *
 * @param name
 * @param price
 * @param apid (optional)
 * @param orderid
 * @return success status
 */
- (BOOL)trackAction:(NSString *)name
              price:(NSString *)price
            orderid:(NSString *)orderid;

/**
 * Track action
 *
 * @param name
 * @param price
 * @param apid (optional)
 * @param orderid
 * @return success status
 */
- (BOOL)trackAction:(NSString *)name
              price:(NSString *)price
            orderid:(NSString *)orderid
               apid:(NSString *)apid;

/**
 * Track action once
 *
 * @param name
 * @param apid (optional)
 * @return success status
 */
- (BOOL)trackAction:(NSString *)name
               apid:(NSString *)apid;

/**
 * Track action once
 *
 * @param name
 * @return success status
 */
- (BOOL)trackAction:(NSString *)name;

@end
