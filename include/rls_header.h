#include <stdbool.h>

/*
* This function is responsible for starting the lobby systems functionality.
* Any internal variables that are not initialized outside of this function are set here.
* Calling this function is not a requirement. Other functions remain callable.
*
* @arg loadPath You pass in the directory the system must look for to load all the information saved in the database.
*      If you do not have anything saved/do not wish to load from your database, simply pass in the null string you specified.
*
* @arg nullStr This is the nullString. Whatever you specify here will be used to compare against the loadPath variable.
*
* @note Refusing to call this function may result in undefined behavior.
*
* @newDevs Undefined behavior means your programs behavior will no longer be predictable. Any errors, crashes, bugs, etc. will be
*          unknown and undocumented. You want to avoid undefined behavior at all costs to prevent the risk of unfixable and
*          confusing bugs.
*
* @errors Can cause error codes: #7
*/
void system_startRocketLobbySystem(char* loadPath, char* nullStr);



/*
* This function is responsible for safely and elegantly ending this systems processes. You typically want to call this outside of
* your programs loop so it is called as the program is exiting. Calling this is optional but highly recommended.
*
* @note Refusing to call this function may result in undefined behavior.
*
* @newDevs Undefined behavior means your programs behavior will no longer be predictable. Any errors, crashes, bugs, etc. will be
*          unknown and undocumented. You want to avoid undefined behavior at all costs to prevent the risk of unfixable and
*          confusing bugs.
*/
void system_stopRocketLobbySystem();



/*
* This function will print out all of the database information currently stored in your RAM into the console.
*
* @arg indent This argument is here for formatting the information that gets printed into the console for you.
*      This determines the amount of whitespace used to space out your database information.

* @arg whitespaceChar This argument is here for formatting the information that gets printed into the console for you.
*      You will normally want to pass in the whitespace char, aka ' '. However, if you wish to see something other than
       a whitespace character to separate information you can pass something else in here.
*
* @note This function call can be very expensive if you have a lot of information stored in RAM. Expensive calls could
        potentially halt your programs execution for a few seconds as your CPU executes all the instructions.
*/
void system_displayData(int indent, char whitespaceChar);



/*
* This function is responsible for saving all the database information in RAM into a .json file for loading later.
*
* @arg savePath This argument is used to find the save directory you want to store your database information into.
*
* @note Do NOT add ANY extension to the filepath! No .txt or .rtf or etc., leave the extension blank! Just have the file name.
*/
void system_saveData(char* savePath);



/*
* This function returns true if there has been an RLS error code during runtime. Using this function is purely optional.
* A good use would be to force your program to exit if this function returns true. This is especially handy for languages
* and/or API's that utilize multi-threading, since (unless in a C/C++ runtime environment) threads will mess with the printf()
* functionality that C uses. Error messages may not appear until you exit the program due to this reason. If you run a language
* that runs everything on the main thread (like python) you will not have to worry about this bug.
*
* @returns A boolean stating if there has been an error code during runtime.
*/
bool system_causedErrorCode();



/*
* This function is responsible for informing your program the current state of the lobby system. Stuffing this inside a
* while loop argument is recommended.
*
* @returns A boolean stating if the lobby system is running or not.
*/
bool system_rocketLobbySystemIsRunning();

/*
* This function is responsible for adding a message request that can be polled later during the
* message polling process.
*
* @arg id You want to pass the users discord ID in long int form here.
*
* @arg message You want to specify what this message will say here. If you want to force this
*      request to be invalid, simply pass in the null string.
*
* @arg nullStr This is the nullString. Whatever you specify here will be used to compare
*      against the message variable.
*/
void message_addToQueue(unsigned long long id, char* message, char* nullStr);



/*
* This function is responsible for polling a message request event submitted through the
* "message_addToQueue()" function. You want to stuff this function inside the argument of a while
* loop so the system can properly poll all the message request events.
*
* @returns A boolean that states if the queue is empty or not. If it is empty, this will return false.
*
* @newDevs A boolean is a true or false statement. It will be useful for automatically breaking out
*          of the while loop that polls these events.
*/
bool message_pollMessage();



/*
* This function is responsible for returning the discord ID of the person who will be receiving this
* message.
*
* @returns The currently polled message event's discord ID in long int form.
*
* @note Calling this function outside of a poll message event while loop can result in undefined
*       behavior.
*
* @newDevs Undefined behavior means your programs behavior will no longer be predictable. Any errors, crashes, bugs, etc. will be
*          unknown and undocumented. You want to avoid undefined behavior at all costs to prevent the risk of unfixable and
*          confusing bugs.
*/
unsigned long long message_polledMessageID();



/*
* This function is responsible for returning the message contents that will be sent to the user.
*
* @returns A string containing the message.
*
* @note Calling this function outside of a poll message event while loop can result in undefined
*       behavior.
*
* @newDevs Undefined behavior means your programs behavior will no longer be predictable. Any errors, crashes, bugs, etc. will be
*          unknown and undocumented. You want to avoid undefined behavior at all costs to prevent the risk of unfixable and
*          confusing bugs.
*/
char* message_polledMessageContents();

/*
* This function is responsible for properly creating your game type. All essential internal variables
* will be initialized here.
*
* @arg gameName This will be the name of your game type. This will become case sensitive in other
*      function calls so be certain to type it correctly when passing it into this function.
*
* @arg maxPlayers This will specify the maximum amount of players required before a game starts.
*      Once a game is started no one can join the game's lobby. (As of version 1.0)
*
* @arg isSinglePlayer This will specify if this game is single player. If set to true, this will render
*      the maxPlayers variable useless and will not be considered during the lobby system processes.
*
* @note Failing to call this function will result in near-certain chances of RLS errors and potentially
*       undefined behavior.
*
* @newDevs Undefined behavior means your programs behavior will no longer be predictable. Any errors, crashes, bugs, etc. will be
*          unknown and undocumented. You want to avoid undefined behavior at all costs to prevent the risk of unfixable and
*          confusing bugs.
*/
void properties_insertGame(char* gameName, unsigned short maxPlayers, bool isSinglePlayer);



/*
* This function will insert a game value into your game type's internal properties. You can then set/get
* this value in your game type's game code. Once a game starts, the system will automatically insert this
* value into your game.
*
* @arg gameName This is the game type you'll be changing the value properties of.
*
* @arg valueName This is the key of the value. In game code you will specify this key to get/set the key's
*      long int value.
*
* @arg defaultValue This is the default value this particular key will be automatically set to when it is
*      inserted into your game during game start up time.
*
* @errors Can cause error codes: #1
*/
void properties_insertGameValue(char* gameName, char* valueName, long defaultValue);



/*
* This function will insert a player value into your game type's internal properties. You can then set/get
* this value in your game type's code. Once a game starts, the system will automatically insert/override this
* value on each player in the game. This will make your life easier so certain player-specific values do not
* have to be automatically reset once a player joins a game.
*
* @arg gameName This is the game type you'll be changing the value properties of.
*
* @arg valueName This is the key of the player value. In game code you will specify this key to get/set the key's
*      long int value.
*
* @arg defaultValue This is the default value this particular key will be automatically set to when the game
*      starts and all players get their values reset/inserted.
*
* @errors Can cause error codes: #2
*/
void properties_insertPlayerDefaultValue(char* gameName, char* valueName, long defaultValue);



/*
* This function is responsible for polling game lobbies. If a game is currently active and not finished, this function
* will poll the game for you. You want to stuff this function inside the argument of a while loop so the system can
* properly loop through all the games for you. The body of this while loop will act as your game code for the game type
* you specify.
*
* @arg gameName This is the game type you want to poll.
*
* @returns A boolean that states if there are anymore games needed to poll (of this game type). If there are no more games
*          to poll, this function will return false and break out of the while loop.
*
* @errors Can cause error codes: #9
*/
bool game_pollGame(char* gameName);



/*
* This function returns the ID of the player number you specified.
*
* 
*
* @returns The currently polled game's discord ID of the player number in long int form.
*
* @note Calling this function outside of a poll game while loop can result in undefined
*       behavior.
*
* @newDevs Undefined behavior means your programs behavior will no longer be predictable. Any errors, crashes, bugs, etc. will be
*          unknown and undocumented. You want to avoid undefined behavior at all costs to prevent the risk of unfixable and
*          confusing bugs.
*/
unsigned long long game_getPlayer(unsigned short playerNumber);



/*
* This function will give you the value of the key you specified.
*
* @arg key This is the value you want to get from your polled game.
*
* @returns The value of the key you specified in long int form.
*
* @note Calling this function outside of a poll game while loop can result in undefined
*       behavior.
*
* @newDevs Undefined behavior means your programs behavior will no longer be predictable. Any errors, crashes, bugs, etc. will be
*          unknown and undocumented. You want to avoid undefined behavior at all costs to prevent the risk of unfixable and
*          confusing bugs.
*
* @errors Can cause error codes: #3
*/
long game_getGameValue(char* key);



/*
* This function is responsible for inserting a game value into the currently polled game. Do not confuse this function with the
* properties function variant. "properties_insertGameValue()" inserts a default value into a game type's properties. This function
* inserts a value into the game that is currently polled. If the value does not exist yet, it will insert it. If the value already
* exists (aka if it was automatically inserted when the game started/was manually inserted by you) it will be overwritten.
*
* @arg key This is the indentifier/key you will use to get/set your game value.
*
* @arg value This is the value you want to insert.
*
* @note Calling this function outside of a poll game while loop can result in undefined
*       behavior.
*
* @newDevs Undefined behavior means your programs behavior will no longer be predictable. Any errors, crashes, bugs, etc. will be
*          unknown and undocumented. You want to avoid undefined behavior at all costs to prevent the risk of unfixable and
*          confusing bugs.
*/
void game_insertGameValue(char* key, long value);



/*
* This is the function to call when you want to end the currently polled game.
*
* @arg gameEndedMessage This is the message that will be sent to all the players in the polled game to notify them the game ended.
*      This not only helps inform users that the game they are playing has ended, it can also be used to specify which player won,
*      if the recipient is the winner, and how many points/currency was rewarded. Whatever you'd like to say, specify it here.
*      However, if you do not want to send any message, simply pass in the null string.
*
* @arg nullStr This is the nullString. Whatever you specify here will be used to compare against the gameEndedMessage variable.
*
* @note Any message sent by this function is inserted into the message queue for message polling. This is so you can format the
*       message if that suits your fancy. <br>
*       Calling this function outside of a poll game while loop can result in undefined behavior.
*
* @newDevs Undefined behavior means your programs behavior will no longer be predictable. Any errors, crashes, bugs, etc. will be
*          unknown and undocumented. You want to avoid undefined behavior at all costs to prevent the risk of unfixable and
*          confusing bugs.
*/
void game_endGame(char* gameEndedMessage, char* nullStr);

/*
* This function is responsible for adding this user into the lobby join queue. You will probably want to call this
* function when a user of your discord bot sends a join command like "!join <game>"
*
* @arg id The discord ID of the person attempting to join the lobby queue in long int format.
*
* @arg game The game type the user is requesting to join.
*
* @arg nullString This is the nullString. Whatever you specify here will be used to compare against the game variable.
*      If the compare returns true, the join request will become invalid. Don't worry, invalid requests are handled
*      for you and do not result in any errors or bugs.
*/
void lobby_addUser(unsigned long long id, char* game, char* nullString);



/*
* Unlike most request handlers in this system, nothing is polled with this function. You only need to call it once,
* and all the users currently waiting in the lobby queue will be handled for you. If for whatever reason the request
* fails and the player failed to join a lobby (and the request was not invalid), the player will be notified that
* something internally went wrong and to try again.
*/
void lobby_handleJoinQueue();

/*
* This function is responsible for inserting the user into the systems database. It is recommended you call
* this function every time a user writes a command for your discord bot. The fact that they already exist in
* your database or not is already handled for you in a resource-efficient way. Manually trying to check this
* will be a waste of resources.
*
* @arg id You will pass the discord ID of the user (in long int form) here.
*
* @note Failing to call this function will result in near-certain chances of RLS errors and potentially
*       undefined behavior.
*
* @newDevs Undefined behavior means your programs behavior will no longer be predictable. Any errors, crashes, bugs, etc. will be
*          unknown and undocumented. You want to avoid undefined behavior at all costs to prevent the risk of unfixable and
*          confusing bugs.
*/
void user_insertUser(unsigned long long id);



/*
* This function will insert a value into the specified user id that you can get/set in the future.
*
* @arg id The discord ID of the user in long int form. If you are inside a game loop, you will use "game_getPlayer()"
*      to retrieve the ID you need to pass into this variable.
*
* @arg key The indentifier/key of this value.
*
* @arg value The value you want to insert.
*
* @note This function does not alter the values of ALL users, only the user you specify.
*
* @errors Can cause error codes: #8
*/
void user_insertValue(unsigned long long id, char* key, long value);



/*
* This function is responsible for fetching the value that the user you specified contains.
*
* @arg id The ID of the user you want to get the value from. If you are inside a game loop, you will use "game_getPlayer()"
*      to retrieve the ID you need to pass into this variable.
*
* @arg key The indentifier for the value you want to get from the database.
*
* @returns The value of the key you specified in long int form.
*
* @errors Can cause error codes: #5
*/
long user_getValue(unsigned long long id, char* key);



/*
* This function will insert a string value into the specified user id that you can get/set in the future. This can be useful
* if you want to store the user's discord username.
*
* @arg id The discord ID of the user in long int form. If you are inside a game loop, you will use "game_getPlayer()"
*      to retrieve the ID you need to pass into this variable.
*
* @arg key The indentifier/key of this value.
*
* @arg value The string you want to insert.
*
* @note This function does not alter the values of ALL users, only the user you specify.
*
* @errors Can cause error codes: #8
*/
void user_insertString(unsigned long long id, char* key, char* value);



/*
* This function is responsible for fetching the string that the user you specified contains.
*
* @arg id The ID of the user you want to get the value from. If you are inside a game loop, you will use "game_getPlayer()"
*      to retrieve the ID you need to pass into this variable.
*
* @arg key The indentifier for the value you want to get from the database.
*
* @returns The string of the key you specified.
*
* @errors Can cause error codes: #6
*/
const char* user_getString(unsigned long long id, char* key);



/*
* This function will inform your program if the user you specified contains a specific key. This is useful when inserting keys
* without overwritting the value if the user happens to already contain the key specified.
*
* @arg id The ID of the user you want to check. If you are inside a game loop, you will use "game_getPlayer()"
*      to retrieve the ID you need to pass into this variable.
*
* @arg key The indentifier this function will attempt to find inside the user you specified.
*
* @returns True or false depending on if the key exists inside the user. Returns false if the key is not found.
*
* @note Unlike other functions, this will not cause an error code if the user does not exist. It will simply return false.
*/
bool user_containsKey(unsigned long long id, char* key);

/*
* This function will insert the character input that a user inputted. I suggest you run this when a user of your discord
* bot writes a command that is specifically for inputting an input for the system, like "!input <char>"
*
* @arg The discord ID of the user in long int form.
*
* @arg The character the user inputted.
*
* @note The '!' character is treated as a "there is no input" character. You can still insert this input, no need to check
*       if the character is '!', just keep this in mind.
*/
void input_addInput(unsigned long long id, char input);



/*
* This gets the input of the id you specified.
*
* @arg id The ID of the user you want to get the input from. If you are inside a game loop, you will use "game_getPlayer()"
*      to retrieve the ID you need to pass into this variable.
*
* @returns The character input of this user from the controllerPlugin.
*
* @note Once this function is called, this users input in the controllerPlugin will be reset. Aka, it will now return '!' until
*       overwritten by the add input function.
*/
char input_getInput(unsigned long long id);
