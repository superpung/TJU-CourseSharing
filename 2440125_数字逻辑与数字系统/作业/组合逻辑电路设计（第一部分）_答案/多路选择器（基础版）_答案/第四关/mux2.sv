`timescale 1ns/1ps

module mux2(

	input		[1 : 0] 	D,
    input   			 	sel,
	output   				Y

	);

	assign Y = (sel == 0)? D[0] : D[1];


endmodule
