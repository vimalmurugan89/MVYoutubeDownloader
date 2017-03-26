# MVYoutubeDownloader

I am here with releasing this library to all. whom needs to get video information from youtube. 

I strongly recommend you all to use this for personal use. For me it requires to save some local videos for study purpose.As of now this been developed for ios alone. Moving forward same will be released to different platform like android, ruby and python etc, Swift version of code will be available soon.

# MVYoutube
     This is the base class which has two functions one is download the video from youtube with specific fomrat. Another one is helping you retrieve the video information and download  urls.
     Those methods are,
             1. -(void)getYoutubeVideoInformationForId:(NSString*)videoId hadnler:(CompletionHandler)handler;
             2. -(void)downloadYoutubeVideoForId:(NSString*)videoId format:(DownloadFormat)format type:(DownloadType)type handler:(DownloadHandler)handler
             
     Apart from this two method, It has one more method to check available video format.
             1. -(MVYouTubeObj*)videoTypeFormatAvailable:(NSString*)type format:(NSString*)format;

# MVYoutubeObj

     This is the modal class which is having the video informations. It has the following properties,
             1. NSString *title;
             2. NSString *videoFormat;//Available formats are video/mp4, video/3gpp, video/webm
             3. NSString *downloadURL;
             4. NSString *quality;//Avaiable quality hd720,small, medium
             
# How to use this?
    
     Download this repo and import the MVYoutbe.Framework. No additional steps are required.
     
# How to get youtube video information?
      You just need to passs the videoId from youtube URL,
      [[MVYouTube sharedMVTube]getYoutubeVideoInformationForId:@"dKzl_82PbU4" hadnler:^(NSArray<MVYouTubeObj *> *array,    NSError *error) {
        
        [array enumerateObjectsUsingBlock:^(MVYouTubeObj * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            NSLog(@"data==%@",obj.quality);
        }];
        
    }];
    
# How to download video for specific format?

     [[MVYouTube sharedMVTube]downloadYoutubeVideoForId:@"dKzl_82PbU4" format:^NSString *{
        return gpp;
    } type:^NSString *{
        return small;
    } handler:^(NSData *data, NSURLResponse *response, NSError *error) {
        [data writeToFile:@"~/Desktop/test.3gpp" atomically:YES];
    }];
    
    
    
