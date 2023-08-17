SRC_NAME=Tb.bsv
all: sim verilog

sim: ba
	bsc -sim -o mkTb -e mkTb mkTb.ba

ba: $(SRC_NAME)
	bsc -sim -u $(SRC_NAME)

verilog: $(SRC_NAME)
	bsc -verilog $(SRC_NAME)

clean:
	rm *.bo
	rm mk*
	rm model_*