//
//  OACall.h
//  OAuthConsumer
//
//  Created by Alberto García Hierro on 04/09/08.
//  Copyright 2008 Alberto García Hierro. All rights reserved.
//	bynotes.com

#import <Foundation/Foundation.h>

@class OAProblem;
@class OACall;

@protocol OACallDelegate

- (void)call:(OACall *)call failedWithError:(NSError *)error;
- (void)call:(OACall *)call failedWithProblem:(OAProblem *)problem;

@end

@class OAConsumer;
@class OAToken;
@class OADataFetcher;
@class OAMutableURLRequest;
@class OAServiceTicket;

@interface OACall : NSObject {
	NSObject <OACallDelegate> *delegate;
	SEL finishedSelector;
	OADataFetcher *fetcher;
	OAMutableURLRequest *request;
}

@property(retain, readonly) NSURL *url;
@property(retain, readonly) NSString *method;
@property(retain, readonly) NSArray *parameters;
@property(retain, readonly) NSDictionary *files;
@property(retain, nonatomic) OAServiceTicket *ticket;

- (id)init;
- (id)initWithURL:(NSURL *)aURL;
- (id)initWithURL:(NSURL *)aURL method:(NSString *)aMethod;
- (id)initWithURL:(NSURL *)aURL parameters:(NSArray *)theParameters;
- (id)initWithURL:(NSURL *)aURL method:(NSString *)aMethod parameters:(NSArray *)theParameters;
- (id)initWithURL:(NSURL *)aURL parameters:(NSArray *)theParameters files:(NSDictionary*)theFiles;

- (id)initWithURL:(NSURL *)aURL
		   method:(NSString *)aMethod
	   parameters:(NSArray *)theParameters
			files:(NSDictionary*)theFiles;

- (void)perform:(OAConsumer *)consumer
		  token:(OAToken *)token
		  realm:(NSString *)realm
	   delegate:(NSObject <OACallDelegate> *)aDelegate
	  didFinish:(SEL)finished;

@end
