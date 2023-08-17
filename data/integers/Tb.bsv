package Tb;

(* synthesize *)
module mkTb (Empty);
    Integer inx = 0;

    Bool arr1[4];
    arr1[inx] = True;
    inx = inx + 1;
    arr1[inx] = False;
    inx = inx + 1;
    arr1[inx] = True;
    inx = inx + 1;
    arr1[inx] = True;

    int arr2[16];
    for (Integer i = 0; i < 16; i = i + 1) begin
        arr2[i] = fromInteger(i);
    end

    Integer foo = 10;
    foo = foo + 1;
    foo = foo * 5;
    Bit#(16) var1 = fromInteger(foo);

    Reg#(int) regArr1[5];
    for (Integer i = 0; i < 5; i = i + 1) begin
        regArr1[i] <- mkReg(fromInteger(i * 10));
    end

    Reg#(int) step <- mkReg(0);

    rule init (step == 0);
        Integer x = 10 ** 10000;
        Bool isLarge = (x > 0);
        $display("isLarge = ", isLarge);
        // uncomment this and see the big number created, causing a error :)
        // $display("Large number = ", x);

        step <= step + 1;
    endrule

    rule step1 (step == 1);
        $display("=== step 1 ===");
        for (Integer i = 1; i < 16; i = i * 2)
            $display("i is ", i);
        step <= step + 1;
    endrule

    rule step2 (step == 2);
        $display("=== step 2 ===");
        $write("regArr1: ");
        for (Integer i = 0; i < 5; i = i + 1) begin
            $write("%03d ", regArr1[i]);
            if (i == 4)
                $write("\n");
            regArr1[i] <= regArr1[i] + 1;
        end
        step <= step + 1;
    endrule

    rule step3 (step == 3);
        $display("=== step 3 ===");
        int threshold = 4;
        if (regArr1[0] < threshold) begin
            $display("regArr1[0] is less than %0d. Retry", threshold);
            step <= 2;
            regArr1[4] <= regArr1[4] + 5;
        end
        else begin
            $display("regArr1[0] is equal or greater than %0d", threshold);
            step <= step + 1;
        end
    endrule

    rule step4 (step == 4);
        $display("All done");
        $finish(0);
    endrule
endmodule

endpackage