`timescale 1ns/1ps

module mux8(

	input	[7 : 0] D,
    input   [2 : 0] sel,
	output  logic Y

	);

	always_comb begin

		if (sel == 3'b000) Y = D[0];
		else if (sel == 3'b001) Y = D[1];
		else if (sel == 3'b010) Y = D[2];
		else if (sel == 3'b011) Y = D[3];
		else if (sel == 3'b100) Y = D[4];
		else if (sel == 3'b101) Y = D[5];
		else if (sel == 3'b110) Y = D[6];
		else Y = D[7];
	end


endmodule
