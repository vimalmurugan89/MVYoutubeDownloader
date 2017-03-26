//
//  MVYoutubeObj.h
//  MVYoutubeFramework
//
//  Created by vimal murugan on 26/03/17.
//  Copyright © 2017 Absolute Thought. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MVYoutubeObj : NSObject

@property(nonatomic,strong) NSString *title;
@property(nonatomic,strong) NSString *videoFormat;
@property(nonatomic,strong) NSString *downloadURL;
@property(nonatomic,strong) NSString *quality;

+(instancetype)objectWithDictionary:(NSDictionary*)dict;
@end
