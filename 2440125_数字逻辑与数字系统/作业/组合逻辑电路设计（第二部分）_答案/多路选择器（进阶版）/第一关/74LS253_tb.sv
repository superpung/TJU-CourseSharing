`timescale 1ns/1ps

module _74LS253_tb();

	logic [3 : 0] 	D1, D2;
	logic 		S0, S1, G1_n, G2_n;
	logic 		Y1, Y2;

	integer i;

	_74LS253 DUT(.D1(D1), .D2(D2), .S0(S0), .S1(S1), .G1_n(G1_n), .G2_n(G2_n), .Y1(Y1), .Y2(Y2));

	initial begin

		D1 = 4'b0110;
		D2 = 4'b1001;
		G1_n = 1'b1;
		G2_n = 1'b1;
		{S1, S0} = 2'b00;
		#20;
		G1_n = 1'b0;
		G2_n = 1'b0;

		for(i = 0; i < 4; i = i+1) begin
			
			{S1, S0} = i;
			#20;

		end

	end

        initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t:\nD1 = %b, D2 = %b\nG1_n = %b, G2_n = %b, S1 = %b, S0 = %b\nY1 = %b, Y2 = %b\n*************************************", $time, D1, D2, G1_n, G1_n, S1, S0, Y1, Y2);
	end

	initial begin
		
		$dumpfile("74LS253.vcd");
		$dumpvars(0, _74LS253_tb);

	end

endmodule
