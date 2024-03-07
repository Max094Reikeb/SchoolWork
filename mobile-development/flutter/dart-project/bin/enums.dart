void main(List<String> arguments) {}

enum NetworkStateEnum {
  initial("4O4"),
  inProgress("404"),
  success("404"),
  error("404");

  const NetworkStateEnum(this.state);

  final String state;
}

sealed class NetworkStateClass {}

class InitialState extends NetworkStateClass {}

class InProgressState extends NetworkStateClass {}

class SuccessState extends NetworkStateClass {
  final String state;

  SuccessState(this.state);
}

class ErrorState extends NetworkStateClass {
  final Exception error;

  ErrorState(this.error);
}
