`timescale 1ns/1ps

module adder_8bits(

        input	[7 : 0]	A,
	input	[7 : 0]	B,
	input 		Cin,
	output	[7 : 0] S,
	output 		Cout

	);

	logic [7 : 0] CO;

	fulladder U0(.A(A[0]), .B(B[0]), .Cin(Cin), .S(S[0]), .Cout(CO[0]));
	fulladder U1(.A(A[1]), .B(B[1]), .Cin(CO[0]), .S(S[1]), .Cout(CO[1]));
	fulladder U2(.A(A[2]), .B(B[2]), .Cin(CO[1]), .S(S[2]), .Cout(CO[2]));
	fulladder U3(.A(A[3]), .B(B[3]), .Cin(CO[2]), .S(S[3]), .Cout(CO[3]));
	fulladder U4(.A(A[4]), .B(B[4]), .Cin(CO[3]), .S(S[4]), .Cout(CO[4]));
	fulladder U5(.A(A[5]), .B(B[5]), .Cin(CO[4]), .S(S[5]), .Cout(CO[5]));
	fulladder U6(.A(A[6]), .B(B[6]), .Cin(CO[5]), .S(S[6]), .Cout(CO[6]));
	fulladder U7(.A(A[7]), .B(B[7]), .Cin(CO[6]), .S(S[7]), .Cout(CO[7]));

	assign Cout = CO[7];

endmodule
