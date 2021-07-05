`timescale 1ns/1ps

module mux4(

	input		[3 : 0] 	D,
    input   	[1 : 0] 	sel,
	output   				Y

	);
	
	logic mux0_out, mux1_out;

	mux2 U0(.D(D[1:0]), .sel(sel[0]), .Y(mux0_out));
	mux2 U1(.D(D[3:2]), .sel(sel[0]), .Y(mux1_out));
	mux2 U2(.D({mux1_out, mux0_out}), .sel(sel[1]), .Y(Y));


endmodule
