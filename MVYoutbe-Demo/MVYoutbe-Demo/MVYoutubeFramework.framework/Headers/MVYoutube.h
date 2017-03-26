//
//  MVYoutube.h
//  MVYoutubeFramework
//
//  Created by vimal murugan on 26/03/17.
//  Copyright © 2017 Absolute Thought. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MVYoutubeObj.h"

//It belongs to video format
extern NSString *mp4;
extern NSString *webm;
extern NSString *gpp;

//It belongs to Video type
extern NSString *small;
extern NSString *medium;
extern NSString *hd720;

typedef void (^CompletionHandler)(NSArray<MVYoutubeObj*>* array,NSError *error);
typedef void (^DownloadHandler)(NSData *data,NSURLResponse *response,NSError *error);

typedef  NSString* (^DownloadFormat)();
typedef  NSString* (^DownloadType)();

@interface MVYoutube : NSObject

+(instancetype)sharedMVTube;

/**
   Checking the avaiable video format for specific youtube url's
   @param type - It can be anything from video types (small,medium,gpp).
   @param format - It can be anything from video format (mp4,webm,gpp).
   @return MVYoutubeobj - Retrutn the modal objects which is having the video information if type is exist.
 */
-(MVYoutubeObj*)videoTypeFormatAvailable:(NSString*)type format:(NSString*)format;

/**
  Getting the available video informations for specific videoId
  @param videoId - Youtube video id
  @param handler - CompletionHandler retruning the available formats. Retrun error if any error occured during the communication.
 */
-(void)getYoutubeVideoInformationForId:(NSString*)videoId handler:(CompletionHandler)handler;

/**
  Downloading the video for specific formats
  @param videoId - Youtube video id.
  @param format - DownloadFormat It can be anything from video format (mp4,webm,gpp).
  @param type - DownloadType It can be anything from video types (small,medium,gpp).
  @param handler - CompletionHandler retruning the data of video, response and Retrun error if any error occured during the downloads.
 */
-(void)downloadYoutubeVideoForId:(NSString*)videoId format:(DownloadFormat)format type:(DownloadType)type handler:(DownloadHandler)handler;

@end
