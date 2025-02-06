# Calendar Program in C

## Introduction

This program is a simple calendar application written in C. It takes a year and a month as input and displays the corresponding monthly calendar with a formatted output.

## Features

- Displays a monthly calendar for a given year and month.
- Uses `gotoxy()` function to position text in the console.
- Changes text color for better visibility using `SetColor()`.
- Highlights weekends and organizes days in a structured format.

## Prerequisites

- Windows OS (as it uses `windows.h` for console manipulation).
- A C compiler like GCC (MinGW for Windows) or Turbo C.

## How to Compile and Run

1. Open a terminal or command prompt.
2. Navigate to the directory where the file is saved.
3. Compile using:
   ```sh
   gcc calendar.c -o calendar.exe
   ```
4. Run the program:
   ```sh
   calendar.exe
   ```
5. Enter the year and month when prompted.

## Code Explanation

- **`gotoxy(int x, int y)`**: Moves the cursor to the specified position on the console.
- **`SetColor(int ForgC)`**: Sets text color for console output.
- **`display(int nyr, int nmonth, int tdays, int days[])`**: Displays the calendar for the given year and month.
- **`calendar(int nyr, int nmonth)`**: Computes the number of days and determines the first day of the month.

## Example Input/Output

```
Enter year and month(number): 2024 2

                February 2024
Mon  Tue  Wed  Thu  Fri  Sat  Sun
     1    2    3    4
5    6    7    8    9   10   11
12   13   14   15   16   17   18
19   20   21   22   23   24   25
26   27   28   29
```

## Notes

- The program supports years starting from 1945.
- It correctly accounts for leap years.
- The console must support Windows API functions for proper execution.

## Future Enhancements

- Add navigation features to move between months using arrow keys.
- Provide a full-year calendar view.
- Implement a GUI version using C++ or another language.

## Created By

Diyansi Chaudhary

