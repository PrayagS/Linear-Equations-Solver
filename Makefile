CC = gcc
CFLAGS = -Wall
ODIR=obj
LIBS=-lm # math library

# Replaces the obj filenames with their complete filepath
# $(patsubst pattern, replacement, text to be replaced)
# % is wild character
_OBJ = Main.o InputMatrix.o GaussianElimination.o PrintMatrix.o SwapRows.o SwapCols.o BackSubstitution.o FatMatrix.o TallMatrix.o CheckRows.o FindNullSpace.o TraceColsExchange.o SwapZeroRows.o ReverseGaussian.o ExtractF.o RowExchange.o SwapTwoRows.o CompareValues.o FindNullSpace.o CompleteSolution.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ)) 

# Compiles all C files
$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

# Generates the final executable
out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
