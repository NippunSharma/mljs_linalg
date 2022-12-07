import { Matrix } from "../classes/Matrix";
import { Col } from "../classes/Col";
import { Row } from "../classes/Row";
import { getInstance } from "../Stream";
import { MatTsType } from "../primitives/Value";

export async function Abs<T extends MatTsType>(A: Matrix<T>): Promise<Matrix<T>> {
  let A_abs = A.newWrapper();
  const instance = await getInstance();

  let inner;

  switch (A.objType()) {
    case "mat":
      switch (A.matType) {
        case "float":
          inner = instance.abs_mat_float(A.getArmaMat());
          break;
        case "int":
          inner = instance.abs_mat_int(A.getArmaMat());
          break;
      }
      break;
    case "col":
      switch (A.matType) {
        case "float":
          inner = instance.abs_col_float(A.getArmaMat());
          break;
        case "int":
          inner = instance.abs_col_int(A.getArmaMat());
          break;
      }
      break;
    case "row":
      switch (A.matType) {
        case "float":
          inner = instance.abs_row_float(A.getArmaMat());
          break;
        case "int":
          inner = instance.abs_row_int(A.getArmaMat());
          break;
      }
      break;
  }

  A_abs.setArmaMat(inner);
  return A_abs;
}
