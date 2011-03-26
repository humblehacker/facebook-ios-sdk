#import "FBRequest.h"

/*
    Uploads video to Facebook using a combination of the old
    and the new API/SDK.

    Please note that this code parses the access token from
    the Facebook class, which is quite brittle, unofficial and
    could easily break with the upcoming SDK releases. Also it
    seems to only work with the older, pop-up authentication and
    not the new one that uses app switching. (The new authentication
    scheme seems to result in a different auth token format
    that we can’t parse.)

    http://bugs.developers.facebook.net/show_bug.cgi?id=10214

    And yet another thing that popped up in follow-up discussions
    is that your application has to be set to HTML/Web, not Native,
    in the Facebook Application Settings:

    http://stackoverflow.com/questions/5355846

    If somebody knows a better, more sane way to upload video
    from iOS to Facebook, I’d be happy to hear about it, so that
    we can deprecate this hack and move towards a better future™.
*/
@interface FBVideoUpload : NSObject
{
    NSString *accessToken;
    NSString *appSecret;
    NSString *apiKey;
}

// The access token from the Facebook class. We need the access
// key to get the session key, so that this param is required if
// you want to upload anything at all.
@property(retain) NSString *accessToken;

// Application secret as shown in the app settings on Facebook.
// This is a required param, since we need the secret to correctly
// compute the request signature.
@property(retain) NSString *appSecret;

// Application API key, also required.
@property(retain) NSString *apiKey;

// The URL has to be a file URL or bad things will happen.
- (void) startUploadWithURL: (NSURL*) movieURL
    params: (NSDictionary*) userParams
    delegate: (id <FBRequestDelegate>) delegate;
    

@end
