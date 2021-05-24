module flipflop (D, Clock, esetn, Q);
    input D, Clock, Resetn;
    output reg Q;
    always @(posedge Clock)
        if (!Resetn)
            Q <= 0;
        else
            Q <= D;
endmodule
    
module test();
    reg Dtest,Clocktest,Resetntest;
    wire Qtest;
    
    initial
    begin
        Dtest           = 0;
        Clocktest       = 0;
        Resetntest      = 1;
        # 10 Resetntest = 0;
        # 60 Resetntest = 1;
        # 10 Dtest      = 1;
        # 40 Dtest      = 0;
    end
    
    always
    #10 Clocktest = ~Clocktest;
    
    flipflop u1(Dtest, Clocktest, Resetntest, Qtest);
    
endmodule
