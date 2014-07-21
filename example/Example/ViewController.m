//
//  ViewController.m
//  Example
//
//  Created by Dmitry Ponomarev on 14/07/14.
//  Copyright (c) 2014 AdOnWeb. All rights reserved.
//

#import "ViewController.h"

@import ActionpayTracker;

@interface ViewController ()

@end

@implementation ViewController
            
- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

- (IBAction)onPurchase:(id)sender {
  [[SLTracker sharedTracker] trackAction:@"purchase" price:@"440" orderid:nil];
}

- (IBAction)onEvent:(id)sender {
  [[SLTracker sharedTracker] trackAction:@"event" apid:nil];
}

@end
