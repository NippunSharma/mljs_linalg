import { MatSize } from "./MatSize.js";
import { MatType } from "../primitives/Value.js";
import { Matrix } from "./Matrix.js";

export class Col<T> extends Matrix<T> {
  constructor(matSize: MatSize, matType: MatType) {
    super({n_cols: 1, n_rows: matSize.n_rows}, matType);
  }

  async init() {
    const { default: instantiate } = await import("../../../resources/webml_linalg");
    const instance = await instantiate();

    switch (this.matType) {
      case "double":
        this.armaMat = new instance.arma_col_double();
        this.armaMat.set_size(this.matSize.n_rows);
        break;
      case "float":
        this.armaMat = new instance.arma_col_float();
        this.armaMat.set_size(this.matSize.n_rows);
        break;
      case "int":
        this.armaMat = new instance.arma_col_int();
        this.armaMat.set_size(this.matSize.n_rows);
        break;
      default:
        this.armaMat = new instance.arma_col_double();
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
}
