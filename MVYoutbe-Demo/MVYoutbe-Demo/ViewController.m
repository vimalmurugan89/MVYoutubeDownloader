//
//  ViewController.m
//  MVYoutbe-Demo
//
//  Created by vimal murugan on 26/03/17.
//  Copyright © 2017 Absolute Thought. All rights reserved.
//

#import "ViewController.h"
#import <MVYoutubeFramework/MVYoutubeFramework.h>

@interface ViewController ()
@property(nonatomic,weak)IBOutlet UIActivityIndicatorView *activityIndicatorView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.activityIndicatorView setHidesWhenStopped:YES];
    [self.activityIndicatorView setHidden:YES];
}

-(IBAction)getVideoInfo:(id)sender{
    [self showIndicator];
    [[MVYoutube sharedMVTube]getYoutubeVideoInformationForId:@"dKzl_82PbU4" handler:^(NSArray<MVYoutubeObj *> *array, NSError *error) {
        [self hideIndicator];
        if (!error){
            [array enumerateObjectsUsingBlock:^(MVYoutubeObj * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                NSLog(@"url - %@ \ntitle - %@",obj.downloadURL,obj.title);
            }];
        }else{
            NSLog(@"error %@",[error localizedDescription]);
        }
    }];
}

-(IBAction)downloadVideo:(id)sender{
    
    [self showIndicator];
    [[MVYoutube sharedMVTube]downloadYoutubeVideoForId:@"dKzl_82PbU4" format:^NSString *{
        return gpp;
    } type:^NSString *{
        return small;
    } handler:^(NSData *data, NSURLResponse *response, NSError *error) {
        
        [self hideIndicator];
        if (!error)
            [data writeToFile:@"Path to save (/Downloads/test.3gpp)" atomically:YES];
        else
            NSLog(@"error==%@",[error localizedDescription]);
    }];
}

-(void)showIndicator{
    self.view.userInteractionEnabled=NO;
    [self.activityIndicatorView setHidden:NO];
    [self.activityIndicatorView startAnimating];
}

-(void)hideIndicator{
    self.view.userInteractionEnabled=YES;
    [self.activityIndicatorView stopAnimating];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
