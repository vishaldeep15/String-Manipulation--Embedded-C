# String-Manipulation--Embedded-C
Academic project for string reversal and alphabetical sorting in Embedded C using Keil C 51 for 8051

Running the Program in Keil C51
1. Build Target: To build the target go to Project and select “Build Target” or press F7 as a shortcut key. 
                 Output window will show the compilation results. If there are no errors, then we can go ahead to run the program.
2. Debug: To debug the program, go to Debug and click on “Start/Stop Debug Session” or directly press Ctrl+F5.
3. Run: To run the program, the serial window should be open first by going to View and selecting “Serial Window #1”. Then again press 
        Debug and select “Go” to execute the program. After that in serial window #1 enter the desired input string. The results will be 
        displayed in the serial window itself. 
        
Expected Output
        
The program takes a character array or string as input. When “Enter” is pressed it produces three strings as output. 
Let us suppose entered string is “My name is Vishal Deep”. Then the output strings produced will be

1. “My name is Vishal Deep” (Redisplay the input string entered).
2. “Deep Vishal is name My” (Reverse the order of words in the string).
3. “My aemn is ahilsV Deep” (alphabetically sort characters in each word of the string irrespective of case).
