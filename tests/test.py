import pyhaversine as haversine

assert haversine.__version__ == '0.0.1'
assert haversine.haversine((1.0, 2.0), (3.0, 4.0)) == 314491.6589874878
