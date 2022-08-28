# vec
A simple C dynamic vector library.<br />
Works with any type. Even structs.<br />
<br />
Doc:<br />
Vec: the vector struct. contains: the vector itself, the size, the typesize.<br />
<br />
vecNew: macro function used to init the vector size to 0. returns a vector.<br />
<br />
vecGetElem: macro function used to get a vector element. Params: vector, index, element type. returns the element.<br />
<br />
vecPush: function used to insert an element at the front of a vector. Params: vector, element to insert.<br />
<br />
vecPop: function used to get an element out of a vector, starting at the front. Params: vector, element to get out.<br />
<br />
vecFree: variadic function used to free vectors. Params: number of vectors to be freed, vectors to free.<br />
<br />
ttAlloc: function used by the API to initialize a vector's memory. Not meant to be used by the user.<br />
ttResize: function used by the API to resize a vector. Not meant to be used by the user.<br />

Example usage:

Vec vec = vecNew();<br />
int n = 2;<br />
vecPush(&vec, &n);<br />
<br />
for (int i = 0; i < vec.size; i++)<br />
{<br />
&nbsp;&nbsp;&nbsp;&nbsp;printf("ELEM %d: %d", i, vecGetElem(vec, i, int));<br />
}<br />
<br />
vecFree(1, vec);
