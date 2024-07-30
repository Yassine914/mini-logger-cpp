# mini-logger.cpp
A mini header-only logger class.

## Usage

to log a message you first specify the type from these:
    - LOG_FATAL
    - LOG_ERROR
    - LOG_WARN
    - LOG_DEBUG
    - LOG_TRACE
    - LOG_INFO

then you specify the message after the << operator:

example:
```cpp
Log(LOG_INFO) << "message\n";
```

you could use the macros provided or the enum LogLevel to acess/provide the log type.

example:
```cpp
// with macro
Log(LOG_WARN) << "hello" << "\n";
// with enum
Log(LogLevel::WARN) << "hello \n";
// both will print the same output
// [WARN TIME] hello
```

you can set the log level(priority), such that anything below that level will not be shown.
example:
```cpp
// by default the log level is LOG_INFO
// this means log everything
Log(LOG_INFO) << "HELLO WORLD\n";

// function to set the log level.
// could take an enum value as well like LogLevel::WARN
Log.SetLogLevel(LOG_WARN);

Log(LOG_INFO) << "this should not show\n";
Log(LOG_WARN, FILE_INFO) << "this should show\n";
```

## Logging to files.

you can use the EnableFileOutput() function.
it can take an optional filepath
    - if not specified, the output will be directed to "logger.txt"

## Extra Parameters - File:Line info

you can specify that a certain log message will output the file name and line number it was called from.

example:
```cpp
Log(LOG_ERROR, FILE_INFO) << "hello\n";
// output:
// [ERROR TIME ./README.md:60]  hello
```

LOG() is a macro that automatically provides the file info without needing to specifying it.

example:
```cpp
LOG(LOG_ERROR, "hello" << "\n");
// NOTE: that the entire line is wrapped inside the macro
// unlike the previous examples
```

## Colors

specified colors:
    - TEXT_RED
    - TEXT_GREEN 
    - TEXT_YELLOW
    - TEXT_BLUE  
    - TEXT_PURPLE
    - TEXT_CYAN  
    - TEXT_WHITE

note that colors are not output to the file.
- To disable colors, comment this line in the logger.h file:
```cpp
24 #define TEXT_COLORS
```

## Extras: Timer Class

a simple timer class that outputs the duration of a block of code.
it starts when it is initialized like:
```cpp
Timer myTimer("timethisfunction", true);
```
the constructor takes a name and if it should be in ms (true) or sec (false)

the timer will output the duration after it exits the scope or explicitly deleted.
output example:
```cpp
timethisfunction: 24.234s
```

you could also get the duration explicitly using the GetCurrentDuration(bool ms) function
the argument also specifies whether to output it in ms (true) or sec (false)
