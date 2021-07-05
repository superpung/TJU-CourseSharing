module alu_8bits(

    input	[7 : 0]	A,
	input	[7 : 0]	B,
	input   [3 : 0] aluop,
	output	[7 : 0] alu_res,
	output 	logic	ZF,
	output	logic	SF,
	output	logic	CF,
	output	logic	OF

	);

    localparam	ADD   =	4'b0000;
	localparam	SUB   =	4'b0001;
	localparam	AND   =	4'b0010;
	localparam	OR    =	4'b0011;
	localparam	NOT   =	4'b0100;
	localparam	XOR   =	4'b0101;
	localparam	SLL   =	4'b0110;
	localparam	SRL   =	4'b0111;
	localparam	SRA   =	4'b1000;
	localparam	SLT   =	4'b1001;
	localparam	SLTU  =	4'b1010;

	logic 		Sub, Cout;
	logic [7 : 0] 	B_mux, S, tmp_res;

	assign Sub = (aluop == SUB | aluop == SLT | aluop == SLTU)? 1'b1 : 1'b0; 
	assign B_mux = (aluop == SUB | aluop == SLT | aluop == SLTU)? ~B : B; 

	always @(*) begin

		case(aluop)
			
			ADD, SUB	  	: tmp_res = S;				
			AND  			: tmp_res = A & B;		
			OR   			: tmp_res = A | B;		
			NOT  			: tmp_res = ~A;			
			XOR  			: tmp_res = A ^ B;		
			SLL  			: tmp_res = A << B[2 : 0];	
			SRL  			: tmp_res = A >> B[2 : 0];	
			SRA  			: tmp_res = $signed(A) >>> B[2 : 0];	
			SLT  			: begin				
                            if({A[7], B[7]} == 2'b10) tmp_res = 8'b0000_0001;
							else if ({A[7], B[7]} == 2'b01) tmp_res = 8'b0000_0000;
							else begin
								if (S[7]) tmp_res = 8'b0000_0001;
								else tmp_res = 8'b0000_0000;
							end

			end
			SLTU 			: begin				

							if(S > A) tmp_res = 8'b0000_0001;
							else tmp_res = 8'b0000_0000;

			end
			default 		: tmp_res = 8'b0000_0000;

		endcase

	end

	always @(*) begin


		if (!tmp_res) ZF = 1'b1;
		else ZF = 1'b0;
	

		case(aluop)

			ADD: begin

				if(S[7] == 1) SF = 1'b1;
				else SF = 1'b0;

				if(((!A[7] && !B_mux[7]) && S[7]) || ((A[7] && B_mux[7]) && (!S[7])) ) OF = 1'b1;
				else OF = 1'b0;

				if (S < A) CF = 1'b1;
				else	CF = 1'b0;			

			end

			SUB : begin

				if(S[7] == 1) SF = 1'b1;
				else SF = 1'b0;

				if(((!A[7] && !B_mux[7]) && S[7]) || ((A[7] && B_mux[7]) && (!S[7])) ) OF = 1'b1;
				else OF = 1'b0;

				if (S > A) CF = 1'b1;
				else	CF = 1'b0;			

			end
			
			default : {SF, OF, CF} = 3'b000;


		endcase

	end

	adder_8bits U0( .A(A), .B(B_mux), .Cin(Sub), .S(S), .Cout(Cout) );

	assign alu_res = tmp_res;

endmodule 