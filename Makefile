clapack:
	cd includes/CLAPACK-3.2.1; \
	make; \
	cd ../../; \
	mkdir build/clapack; \
	mv includes/CLAPACK-3.2.1/F2CLIBS/libf2c.a includes/CLAPACK-3.2.1/blas_*.a includes/CLAPACK-3.2.1/liblapack.a build/clapack; \
	cd includes/CLAPACK-3.2.1; \
	make cleanall; \
	find . -type f -name "*.o" -delete; \
	find . -type f -name "*.a" -delete; \
	cd ../../; \

mljs_linalg:
	emcc src/embind/linalg.cpp -o build/mljs_linalg.js -I includes/armadillo-11.4.2/include build/clapack/blas_*.a build/clapack/liblapack.a build/clapack/libf2c.a --bind \
		-s ALLOW_MEMORY_GROWTH -O3 -s MODULARIZE=1 -s ENVIRONMENT='web' -s SINGLE_FILE=1; \
	cp build/mljs_linalg.js resources/
