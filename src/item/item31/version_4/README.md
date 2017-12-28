# pure virtual functions
Pure virtual functions can't be innered. That means the functions's body cannot be put into *.h. 

# the importance of virtual functions
If there is a parent without any virtual functions, then when transfer object by the reference of parent, the transfered object's typeinfo will be parent's, not child's.
