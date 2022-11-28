@webml/linalg is a linear algebra library for the browser based on [armadillo](https://gitlab.com/conradsnicta/armadillo-code).

@webml/linalg uses Web Assembly to run armadillo code (in C++) in the browser.

### Steps to install.
This library can be installed directly via npm:
```bash
npm install @webml/linalg
```

### Basic usage.
```typescript
import { Matrix } from "@webml/linalg";

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
