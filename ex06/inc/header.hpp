#ifndef HEADER_HPP
# define HEADER_HPP

# define RESET "\033[0m"

// Regular Colors
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define ORANGE "\x1b[38;2;255;165;0m" // ANSI escape code for orange

// Bold
# define BBLACK "\033[1;30m"
# define BRED "\033[1;31m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define BPURPLE "\033[1;35m"
# define BCYAN "\033[1;36m"
# define BWHITE "\033[1;37m"

// Underline
# define UBLACK "\033[4;30m"
# define URED "\033[4;31m"
# define UGREEN "\033[4;32m"
# define UYELLOW "\033[4;33m"
# define UBLUE "\033[4;34m"
# define UPURPLE "\033[4;35m"
# define UCYAN "\033[4;36m"
# define UWHITE "\033[4;37m"

// Background
# define ON_BLACK "\033[40m"
# define ON_RED "\033[41m"
# define ON_GREEN "\033[42m"
# define ON_YELLOW "\033[43m"
# define ON_BLUE "\033[44m"
# define ON_PURPLE "\033[45m"
# define ON_CYAN "\033[46m"
# define ON_WHITE "\033[47m"

// High Intensity
# define IBLACK "\033[0;90m"
# define IRED "\033[0;91m"
# define IGREEN "\033[0;92m"
# define IYELLOW "\033[0;93m"
# define IBLUE "\033[0;94m"
# define IPURPLE "\033[0;95m"
# define ICYAN "\033[0;96m"
# define IWHITE "\033[0;97m"

// Bold High Intensity
# define BIBLACK "\033[1;90m"
# define BIRED "\033[1;91m"
# define BIGREEN "\033[1;92m"
# define BIYELLOW "\033[1;93m"
# define BIBLUE "\033[1;94m"
# define BIPURPLE "\033[1;95m"
# define BICYAN "\033[1;96m"
# define BIWHITE "\033[1;97m"

// High Intensity backgrounds
# define ON_IBLACK "\033[0;100m"
# define ON_IRED "\033[0;101m"
# define ON_IGREEN "\033[0;102m"
# define ON_IYELLOW "\033[0;103m"
# define ON_IBLUE "\033[0;104m"
# define ON_IPURPLE "\033[0;105m"
# define ON_ICYAN "\033[0;106m"
# define ON_IWHITE "\033[0;107m"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*
\x1b: This is the escape character in hexadecimal notation (equivalent to \033 in octal notation or \e in some other representations). It signals the terminal that what follows is a control sequence rather than ordinary characters.

[38;2;255;165;0m: This is the ANSI escape sequence itself. Let's break it down further:

38: This part indicates that the following color code applies to the foreground (text) color. In contrast, 48 would indicate the background color.

2: This specifies that the color will be specified in RGB (red, green, blue) format. This is used to specify true color, allowing for a wider range of colors than the standard 16-color palette.

255;165;0: These are the RGB values for the color. In this case:

255 represents the intensity of red.
165 represents the intensity of green.
0 represents the intensity of blue.
Together, these values produce an orange color. The RGB values are on a scale from 0 to 255, where 0 represents no intensity and 255 represents full intensity for each color component.

m: This terminates the ANSI escape sequence, indicating that the color attributes have been set.
*/

#endif