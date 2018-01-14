type connection;

type configObj;

[@bs.obj]
external makeConfigObj :
  (
    ~host: string=?,
    ~port: int=?,
    ~user: string=?,
    ~password: string=?,
    ~database: string=?,
    unit
  ) =>
  configObj =
  "";

[@bs.module "mysql"] [@bs.val]
external createConnection : configObj => connection = "";

let createConnection = (~host, ~port, ~user) =>
  createConnection(makeConfigObj(~host, ~port, ~user, ()));

type error =
  Js.Nullable.t(
    {
      .
      "code": string,
      "fatal": bool,
      "message": string
    }
  );

type results;

type fields;

[@bs.send]
external query : (connection, string, (error, results, fields) => unit) => unit =
  "";

[@bs.send] external connect : connection => unit = "";

[@bs.send] external endConnection : connection => unit = "end";
