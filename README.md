@ml.js/linalg is a linear algebra library for the browser based on [armadillo](https://gitlab.com/conradsnicta/armadillo-code).

@ml.js/linalg uses Web Assembly to run armadillo code (in C++) in the browser.

### Steps to install.
This library can be installed directly via npm:
```bash
npm install @nippun/linalg
```

### Basic usage.
```typescript
import { Matrix } from "@ml.js/linalg";

async getMatrix() {
  const A: Matrix<number> = new Matrix<number>({ n_rows: 2, n_cols: 2 }, "float");
  await A.init();
  return A;
}

const A = await getMatrix();
A.funcFill((i, j) => i + j); // fill matrix A.
const B = A.t(); // transpose of A.

console.log(A.toString());
console.log(B.toString());
```

### Steps to build.
1. Clone github repo.
```bash
git clone --recurse-submodules https://github.com/NippunSharma/mljs_linalg
```
2. Move to project dir.
```bash
cd mljs_linalg
mkdir -p build
```
3. Build clapack object files first.
```bash
make clapack
```
4. Build `mljs_linalg.wasm` binary along with `mljs_linalg.js`.
```bash
make mljs_linalg
```
5. Now, generate the `dist` dir.
```bash
npm run build
```

Alternatively, you can directly execute `npm run build` and it will
use the pre-existing binary file in `resources/`. However, if anything
is changed in `src/embind`, it is recommended to rebuild the binary.
