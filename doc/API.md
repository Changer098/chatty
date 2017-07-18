JSON-API
####

Format
#####
All API calls follow the same basic procedure derived from the JSON-RPC specification. No HTTP is used, instead GET/POST is defined by the functions themselves. This document attempts to outline both the functions and how they're called.

Protocol
#####
The protocol is effectively the same as JSON-RPC where the format is as follows:
{ "api":{API_version}, "method":{Method Name}, "params":{{JSON encoded Params}}};

This format encompasses the entire body of the transferred message. This message is not encompassed in an HTTP GET or POST message, but simply a plain ascii (maybe UTF-8?) message. However, additional header fields may be inserted above the request. Additional headers must be defined per the API spec, unrecognized headers will not be supported by the Server. Unless you fork this project and add in custom headers, then by all means disregard the previous notion. Anyway, the format for headers is as follows:
{Header Name}: {Header Value} \n
{Header Name}: {Header Value} \n
\n
{RPC message}
Header names and values are case-sensitive. Each Header Name/Value combo must end with a newline or the server will considerate it as an invalid combo. An additonal newline must also be placed after the last Header combo.

Optional Headers
#####
checksum: {int}
	An md5 checksum of the RPC body. A request made to the server with this header will also have a response with this header. If validating the checksum fails, An Exception "MD5.InvalidChecksum" will be returned.
UseStrictFormatting: {Boolean}
	[False by default]
	If True, any message that does not follow the format guide will return the Exception "Format.InvalidFormat".


Functions
#####
	Method: login
	Params: {"name" : string, "password" : string}
	API: 0.1
	Returns: {"cookie" : long}

	Method: sendMessage
	Params: {"cookie" : long, "message" : string}
	API: 0.1
	Returns: 

	Method: getMessages
	Params: {"depth": int}
	API: 0.1
	Returns: {struct[] {"sender": string, "message": string, "timestamp": int}}
