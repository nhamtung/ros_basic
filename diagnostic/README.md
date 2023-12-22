
# Publisher
- /diagnostic_test (diagnostic_msgs/DiagnosticArray): Diagnostic for node

# Test
- Run: $roslaunch diagnostic diagnostic.launch
- Check: $rostopic echo /diagnostic_test