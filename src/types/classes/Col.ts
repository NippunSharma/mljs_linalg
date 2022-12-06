import { MatSize } from "./MatSize.js";
import { MatType, MatTsType } from "../primitives/Value.js";
import { Matrix } from "./Matrix.js";
import { getInstance } from "../Stream.js";

export class Col<T extends MatTsType> extends Matrix<T> {
  constructor(matSize: MatSize, matType: MatType) {
    super({n_cols: 1, n_rows: matSize.n_rows}, matType);
  }

  async init() {
    const instance = await getInstance();

    switch (this.matType) {
      case "float":
        this.armaMat = new instance.arma_col_float();
        this.armaMat.set_size(this.matSize.n_rows);
        break;
      case "int":
        this.armaMat = new instance.arma_col_int();
        this.armaMat.set_size(this.matSize.n_rows);
        break;
      default:
        this.armaMat = new instance.arma_col_float();
        this.armaMat.set_size(this.matSize.n_rows);
    }
  }

  get(i: number): any {
    return this.armaMat.get(i);
  }

  set(i: number, val: any): boolean {
    let changed: boolean = false;
    changed = this.armaMat.set(i, val);
    return changed;
  }

  newWrapper(): Col<T> {
    const A: Col<T> = new Col<T>(this.size, this.matType);
    return A;
  }

  objType(): "mat" | "row" | "col" {
    return "col";
  }
}
