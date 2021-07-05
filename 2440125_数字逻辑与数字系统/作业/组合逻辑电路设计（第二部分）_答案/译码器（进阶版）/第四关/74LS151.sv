`timescale 1ns/1ps

module _74LS151(

	input		[2 : 0]	sel,
	input 		[7 : 0]	D,
	input 			G_n,
	output	logic	 	F,
	output	logic		F_n

	);

	always @(*) begin

		if (G_n) {F, F_n} = 2'b01;
		else begin
			case(sel)
				3'b000 : {F, F_n} = {D[0], ~D[0]};
				3'b001 : {F, F_n} = {D[1], ~D[1]};
				3'b010 : {F, F_n} = {D[2], ~D[2]};
				3'b011 : {F, F_n} = {D[3], ~D[3]};
				3'b100 : {F, F_n} = {D[4], ~D[4]};
				3'b101 : {F, F_n} = {D[5], ~D[5]};
				3'b110 : {F, F_n} = {D[6], ~D[6]};
				3'b111 : {F, F_n} = {D[7], ~D[7]};
			endcase
		end
	end

endmodule
