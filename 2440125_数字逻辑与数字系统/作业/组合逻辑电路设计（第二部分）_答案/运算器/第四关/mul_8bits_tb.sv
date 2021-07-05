`timescale 1ns/1ps

module mul_8bits_tb();

	logic [ 7 : 0] A, B;
	logic [15 : 0] Prod;
	logic Signed;

	mul_8bits U0(

        .A(A),
	.B(B),
	.Signed(Signed),
	.Prod(Prod)

	);

	initial begin

		A = 3;
		B = 5;
		Signed = 1'b0;
		#20;
		A = 3;
		B = 5;
		Signed = 1'b1;
		#20;
		A = -3;
		B = -5;
		Signed = 1'b1;
		#20;
		A = -3;
		B = 5;
		Signed = 1'b1;
		#20;
		A = 5;
		B = -3;
		Signed = 1'b1;
		#20;

	end

        initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: A = %b, B = %b, Signed = %b, Prod = %b", $time, A, B, Signed, Prod);
	end

	initial begin
		
		$dumpfile("mul_8bits.vcd");
		$dumpvars(0, mul_8bits_tb);

	end

endmodule
