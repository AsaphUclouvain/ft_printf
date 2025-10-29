General syntax 

ft_printf("%[0-+#(space)][width][.precision][specifier]", ...)

flags :
  
  0 : left pad the output with 0. (Ex 000005 istead of 5)
      works only when width is specified. When width is specified, 0's are displayed at left instead of spaces
      is ignored when precision or the - flag is used
      works only with those specifiers
      
 - : left justify the output
     the output is by default right justified when this flag is not used
     the width must be specified
     has no effect when the width is less or equal to the length of the value to be printed (including the -sign, digits added by precision, ..etc)

 # : it alternate form of the output depending on the data type 
     it add a 0x or 0X depending on the specifier
     data type supported are : octal, hexadecimal, floats
     is followed by x(hexadecimal lower), X(hexadecimal upper)


 + : show the sign of the value to print
     
 (space) : it print space before a positive number and a minus sign before negative number
           it is like a placeholder for a missing + sign
	   to resume, this flag add a single space(or minus sign for negative number) directly before the data to print.

           
width : the maximum number of chars to use to print the value when this width is less than the value length
        However minimum number of chars to use to represent the value is the value's length

precision : it is the most prioritary property. It apply to the value directly
            it modify the length of the value to be printed
	    it has the priority on the width

SPECIFIERS

 %s : the - flag is the only one which work on it
      the width and the recision are the only properties which works on it
      the precision gives how many chars of the string to print
      the width gives the minimum size of the output

%d : all the flags work on it
     the precision doesn't reduce the value length here
     the width remain the minimum number of charactere to print
     
