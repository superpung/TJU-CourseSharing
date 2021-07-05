`timescale 1ns/1ps

module adder_8bits_tb();

	logic [7 : 0] A, B, S;
	logic Cin, Cout;

	integer i;

	adder_8bits DUT(.A(A), .B(B), .Cin(Cin), .S(S), .Cout(Cout));

	initial begin

		A = 8'b00100001;
		B = 8'b00101101;
		Cin = 1'b1;
		#20;
		A = 8'b10100001;
		B = 8'b10001111;
		Cin = 1'b0;
		#20;
		A = 8'b01111001;
		B = 8'b01101101;
		Cin = 1'b1;
		#20;
		A = 8'b11101001;
		B = 8'b01100111;
		Cin = 1'b0;
		#20;

	end

        initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: A = %b, B = %b, Cin = %b, Cout = %b, S = %b", $time, A, B, Cin, Cout, S);
	end

	initial begin
		
		$dumpfile("adder_8bits.vcd");
		$dumpvars(0, adder_8bits_tb);

	end

endmodule
