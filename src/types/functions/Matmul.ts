import { Matrix } from "../classes/Matrix.js";
import { MatTsType } from "../primitives/Value.js";
import { getInstance } from "../Stream.js";

export async function Matmul<T extends MatTsType>(
  matA: Matrix<T>,
  matB: Matrix<T>
): Promise<Matrix<T>> {
  if (matA.size.n_cols !== matB.size.n_rows) {
    throw `Size of matrices are not compatible, ${matA.size.n_cols} != ${matB.size.n_rows}.`;
  }

  const n_rows = matA.size.n_rows;
  const n_cols = matB.size.n_cols;

  const instance = await getInstance();

  if ((matA.matType === "float") && (matB.matType === "float")) {
    const inner = instance.matmul_float_float((await matA.asMat()).getArmaMat(), (await matB.asMat()).getArmaMat());
    const result = new Matrix<T>({ n_rows, n_cols }, "float");
    result.setArmaMat(inner);
    return result;
  } else if ((matA.matType === "int") && (matB.matType === "int")) {
    const inner = instance.matmul_int_int((await matA.asMat()).getArmaMat(), (await matB.asMat()).getArmaMat());
    const result = new Matrix<T>({ n_rows, n_cols }, "int");
    result.setArmaMat(inner);
    return result;
  } else {
    const a = (await matA.asMat()).getArmaMat();
    const b = (await matB.asMat()).getArmaMat();

    const inner = instance.matmul_float_int(matA.matType === "float" ? a: b,
      matB.matType === "int" ? b: a);
    const result = new Matrix<T>({ n_rows, n_cols }, "float");
    result.setArmaMat(inner);
    return result;
  }
}
