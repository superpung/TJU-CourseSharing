SECTIONS
{
	. = 0x100000;
	.text : 
	{
		obj/testcase/start.o(.text)
		*(.text)
	}
}
