# Huffman_coding
The C program for Huffman coding Technique using a string data -[ data compression ] 
The input given to the program is a string and the ouput given sorted string of huffman encoded data.


# For Example:
   
    Input: sseasoseoeaieiestseossieiaeiuiaieeiaeueaiuiasaeieauasisess
    
  a = 10, e = 15, i = 12, o = 3, s = 13, t = 1, u = 4 : -> (58)
  
  Each char 8 bits -> 58 * 8 = 464 bits
   
    Output (sorted string) :- 
                        
                        a = 111           [  10 * 3 = 30  ]
                        e = 10            [  15 * 2 = 30  ]
                        i = 00            [  12 * 2 = 24  ]
                        o = 11001         [   3 * 5 = 15  ]
                        s = 01            [  13 * 2 = 26  ]
                        t = 11000         [   1 * 5 = 5   ]
                        u = 1101          [  4 * 4 = 16   ]
                        
                        SUM ----------------------->  146 bits
                        
          
     Each char 8 bit  - total char  7 * 8 = 56 bits
                               
                                Frequency = 58 bits
      
                                      SUM = 146 bits
                   -------------------------------
                           Encoded size ---> 260 bits 
                                            ------
                           
                           Saved size --> 464 - 260 = 204 bits
                           
