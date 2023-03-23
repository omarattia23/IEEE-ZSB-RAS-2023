/*
What is the size of the previous enum? 
If we add some extra members to the enum 
what would be the new size and why?
*/
////////////////////////////////////////////
/*
The size of the enum is equal to the size of an integer in the target platform.
If we add some extra members to the enum, 
the new size would depend on the number of members added 
and the underlying integer type used to represent the enum.
If the number of members added is less 
than the maximum value that can be represented 
by the underlying integer type, the size of the enum would not change.

*/

