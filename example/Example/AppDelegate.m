//
//  AppDelegate.m
//  Example
//
//  Created by Dmitry Ponomarev on 14/07/14.
//  Copyright (c) 2014 AdOnWeb. All rights reserved.
//

#import "AppDelegate.h"

@import ActionpayTracker;

@interface AppDelegate ()<SLTrackerDelegate>

@end

@implementation AppDelegate
            

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  // Инициализируем параметры трэкера
  [SLTracker initTest:@"sltestscheme" /* URL scheme */ installUrl:nil];
  // Установим время автоматической отсылки событий
  [[SLTracker sharedTracker] setUpdateInterval:10 repeat:YES];
  // Начать следить за состоянием изменения подключения к интернету
  [[SLTracker sharedTracker] connectionListenerStart];
  // Установить делегат для контроля цикла обработки событий
  [[SLTracker sharedTracker] setDelegate:self];

  return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
  // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
  // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
  // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
  // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
  // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
  // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
  // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

#pragma mark – SmartLeadTracker selegate

- (BOOL)onBeginTrack:(id)sender action:(SLAction *)action
{
  NSLog(@"onBeginTrack: %@ action: %@", sender, action.name);
  return YES;
}

- (BOOL)onBeginSend:(id)sender action:(SLAction *)action
{
  NSLog(@"onBeginSend: %@ action: %@", sender, action.name);
  return YES;
}

- (void)onEndSend:(id)sender action:(SLAction *)action
{
  NSLog(@"onEndSend: %@ action: %@ -> %d", sender, action.name, action.sent);
}

@end
